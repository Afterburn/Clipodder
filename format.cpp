
#include "format.hpp"


std::string format::get_extension(std::string media_url)
{
  std::string extension;
  int index;

  index = media_url.find_last_of(".");
  
  if (index)
    {
      extension = media_url.substr(index+1, media_url.size());
    }

  return extension;
}


std::string format::determine_format(std::string media_url)
{
  std::string extension;
  extension = get_extension(media_url);
  
  std::string video = "video";
  std::string audio = "audio";
  std::string no_fmt;

  if (extension == "mp4")
    {
      return video;
    }

  else if (extension == "mp3")
    {
      return "audio";
    }

  else 
    {
      return no_fmt;
    }
}


std::string format::parse_given_extension(std::string to_parse)
{
  std::string return_string; 
  
  int index = to_parse.find_last_of('/');
  
  if (!index)
    {
      return return_string;
    }

  return_string = to_parse.substr(index+1, to_parse.size());

  return return_string;
}

std::string format::parse_given_format(std::string to_parse)
{
  std::string return_string;

  int index = to_parse.find_last_of("/");
  
  if (!index)
    {
      return return_string;
    }

  return_string = to_parse.substr(0, index);
  
  return return_string;
}  


bool format::defined_type(std::vector<std::string> format_vector, std::string extension, std::string format)
{
  std::vector<std::string>::iterator f_iter;
  
  for (f_iter = format_vector.begin(); f_iter != format_vector.end(); f_iter++)
    {
      if (*f_iter == format || *f_iter == extension)
	{
	  if (debug::state)
	    {
	      std::cout << "supported type: " << *f_iter << std::endl;
	    }
	  return true;
	}
   
    }

  return false;
}

std::string format::get_filename(std::string url)
{
  std::string return_string;
  int start = url.find_last_of("/");
  
  if (!start)
    {
      return return_string;
    }

  return_string = url.substr(start+1, url.size());  
}

