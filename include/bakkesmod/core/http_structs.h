#pragma once

/// <summary>
/// key value pair for field name and field data.
/// If you use a file field. the data should be the path to the file
/// </summary>
struct FormField
{
	enum class Type
	{
		kString,
		kFile
	};

	Type field_type;
	// curlpp doesn't seem to support wstring for the formparts
	std::string data;
	std::string name;
};

typedef std::function<void(double download_size, double downloaded, double upload_size, double uploaded)> CurlProgressFunction; 
typedef std::function<void(int http_status_code, std::string data)> CurlRequestDoneStringReturn;
typedef std::function<void(int http_status_code, std::wstring path)> CurlRequestDoneFileReturn;
typedef std::function<void(int http_status_code, char* data_ptr, size_t data_size)> CurlRequestDoneBinaryReturn;

struct CurlRequest
{
	std::string url;
	std::string verb;
	//std::vector<std::string> headers;
	std::map<std::string, std::string> headers;
	std::string body;
	std::vector<FormField> form_data;
	CurlProgressFunction progress_function;
};
