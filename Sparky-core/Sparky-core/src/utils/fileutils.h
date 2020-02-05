#pragma once

#include <string>

namespace sparky {

	class FileUtils
	{
	public:
		static std::string read_file(const char* filepath)
		{
			FILE* file = fopen(filepath, "rt"); // Open the file as 'read' & 'text'
			fseek(file, 0, SEEK_END); // Measure from the beginning of the file
			unsigned long length = ftell(file); // Retrieve the length of the file in number of bytes
			char* data = new char[length + 1]; // +1 is for termination capture
			memset(data, 0, length + 1); // Set data to 0
			fseek(file, 0, SEEK_SET); // Reset seek position of file
			fread(data, 1, length, file); // Read all of the file into data
			fclose(file);

			std::string result(data); // Store the data into a string, result
			delete[] data; // Delete the pointer data
			return result;
		}

	};

}