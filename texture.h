#ifndef __TEXTURE__
#define __TEXTURE__

#include <windows.h>		//Windows header file

#define BITMAP_ID 0x4D42

class Texture
{
public:
	GLubyte* data;			//Image data (up to 32 bits)
	unsigned int bpp;		//Image color depth in bits per pixel
	float width;			//Image width
	float height;			//Image height
	unsigned int ID;		//Texture ID used to select a texture
	
	Texture() {	}
	
	~Texture()
	{	
		if(data)
			delete data;	
	}	
	
	bool LoadTGA(char* filename, GLfloat minFilter, GLfloat maxFilter)
	{    
		GLubyte		TGAheader[12]={0,0,2,0,0,0,0,0,0,0,0,0};	//Uncompressed TGA header
		GLubyte		TGAcompare[12];					//Used to compare TGA header
		GLubyte		header[6];						//The first six useful bytes from the header
		GLuint		bytesPerPixel;					//Holds the bpp of the TGA
		GLuint		imageSize;						//Used to store image size while in RAM
		GLuint		temp;							//Temp variable
		GLuint		type=GL_RGBA;					//Set the default OpenGL mode to RBGA (32 BPP)
		
		FILE* file = fopen(filename, "rb");			// Open The TGA File
		
		if(file==NULL													   ||	// Does File Even Exist?
			fread(TGAcompare,1,sizeof(TGAcompare),file)!=sizeof(TGAcompare) ||	// Are There 12 Bytes To Read?
			memcmp(TGAheader,TGAcompare,sizeof(TGAheader))!=0			   ||	// Does The Header Match What We Want?
			fread(header,1,sizeof(header),file)!=sizeof(header))					// If So Read Next 6 Header Bytes
		{
			if(file==NULL)							// Did The File Even Exist? *Added Jim Strong*
			{
				printf("%s does not exist.", filename);
				return false;							
			}
			else
			{
				fclose(file);						// If anything failed, close the file
				printf("Could not load %s correctly, general failure.", filename);
				return false;						
			}
		}
		
		width = header[1] * 256 + header[0];		// Determine The TGA Width	(highbyte*256+lowbyte)
		height= header[3] * 256 + header[2];		// Determine The TGA Height	(highbyte*256+lowbyte)
		
		if(width	<=0	||							// Is The Width Less Than Or Equal To Zero
			height<=0	||							// Is The Height Less Than Or Equal To Zero
			(header[4]!=24 && header[4]!=32))		// Is The TGA 24 or 32 Bit?
		{
			fclose(file);							// If Anything Failed, Close The File
			printf("%s's height or width is less than zero, or the TGA is not 24 or 32 bits.", filename);
			return false;							
		}
		
		bpp	 = header[4];							// Grab The TGA's Bits Per Pixel (24 or 32)
		bytesPerPixel= bpp/8;						// Divide By 8 To Get The Bytes Per Pixel
		imageSize	 = width*height*bytesPerPixel;	// Calculate The Memory Required For The TGA Data
		
		data= new GLubyte [imageSize];				// Reserve Memory To Hold The TGA Data
		
		if(data==NULL ||							// Does The Storage Memory Exist?
			fread(data, 1, imageSize, file)!=imageSize)	// Does The Image Size Match The Memory Reserved?
		{
			if(data!=NULL)							// Was Image Data Loaded
				free(data);							// If So, Release The Image Data
			
			printf("Storate memory for %s does not exist or is corrupted.", filename);
			
			fclose(file);							// Close The File
			return false;							// Return False
		}
		
		for(GLuint i=0; i<int(imageSize); i+=bytesPerPixel)		// Loop Through The Image Data
		{										// Swaps The 1st And 3rd Bytes ('R'ed and 'B'lue)
			temp	 =data[i];						// Temporarily Store The Value At Image Data 'i'
			data[i]	 = data[i + 2];					// Set The 1st Byte To The Value Of The 3rd Byte
			data[i+2]= temp;						// Set The 3rd Byte To The Value In 'temp' (1st Byte Value)
		}
		
		fclose (file);								//Close the file
		
		// Build A Texture From The Data
		glGenTextures(1, &ID);						//Generate OpenGL texture IDs
		
		glBindTexture(GL_TEXTURE_2D, ID);			//Bind the texture to a texture object 
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);	//Filtering for if texture is bigger than should be
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, maxFilter);	//Filtering for if texture is smaller than it should be
		
		if(bpp==24)									//Was the TGA 24 bpp?
			type=GL_RGB;							
		
		glTexImage2D(GL_TEXTURE_2D, 0, type, width, height, 0, type, GL_UNSIGNED_BYTE, data);
		
		printf("Loaded %s correctly.", filename);
		return true;
	}
	
	bool LoadBMP(char* filename, GLfloat minFilter, GLfloat maxFilter)
	{
		FILE* file;									//The file pointer
		BITMAPFILEHEADER	file_header;			//The bitmap file header
		BITMAPINFOHEADER	info_header;
		int					imageIdx = 0;			//Image index counter
		unsigned char		tempRGB;				//Swap variable
		
		//Open filename in read only binary mode
		file= fopen(filename, "rb");
		if(file==NULL)
		{
			printf("Could not load %s", filename);
			return false;
		}
		
		//Read the bitmap file header
		fread(&file_header, sizeof(BITMAPFILEHEADER), 1, file);
		
		//Confirm that this is a bitmap by checking for the universal bitmap id
		if(file_header.bfType != BITMAP_ID)
		{
			fclose(file);
			printf("%s is not a .bmp", filename);
			return false;
		}
		
		//Read the bitmap information header in
		fread(&info_header, sizeof(BITMAPINFOHEADER), 1, file);
		
		//Advance the file pointer to the beginning of the bitmap data
		fseek(file, file_header.bfOffBits, SEEK_SET);
		
		//Allocate the bitmap image data
		data= new unsigned char [info_header.biSizeImage];
		
		//Confirm memory allocation
		if(!data)
		{
			free(data);
			fclose(file);
			printf("Could not allocate memory for %s", filename);
			return false;
		}
		
		//Read in the bitmap image data
		fread(data, 1, info_header.biSizeImage, file);
		
		//Make sure bitmap image data was read
		if(data==NULL)
		{
			fclose(file);
			printf("Could not read %s", filename);
			return false;
		}
		
		width = info_header.biWidth;
		height= info_header.biWidth;
		bpp	  = info_header.biBitCount;
		
		//Swap the R and B values to get RGB since the bitmap color format is in BGR
		for(imageIdx = 0; imageIdx<(int)info_header.biSizeImage; imageIdx+=3)
		{
			tempRGB			= data[imageIdx];
			data[imageIdx]  = data[imageIdx + 2];
			data[imageIdx+2]= tempRGB;
		}
		
		//Close the file and return the bitmap image data
		fclose(file);
		
		//Build A Texture From The Data
		glGenTextures(1, &ID);						//Generate OpenGL texture IDs
		
		glBindTexture(GL_TEXTURE_2D, ID);			//Bind the texture to a texture object 
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);	//Filtering for if texture is bigger than should be
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, maxFilter);	//Filtering for if texture is smaller than it should be
		
		if(bpp==32)
			bpp=GL_RGBA;
		
		if(bpp==24)									//Was the TGA 24 bpp?
			bpp=GL_RGB;							
		
		glTexImage2D(GL_TEXTURE_2D, 0, bpp, width, height, 0, bpp, GL_UNSIGNED_BYTE, data);
		
		printf("Loaded %s correctly", filename);
		return true;
	}	
};

#endif