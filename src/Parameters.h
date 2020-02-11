#ifndef PARAMETERS_H_
#define PARAMETERS_H_

class Parameters {
  private:
    float zPixelWidth = 0.0;
    float zPixelHeight = 0.0;
    std::string zImageListFilename = "";
    std::string zDataDirectory = "";
  public:
    Parameters();
    ~Parameters();
    std::string get_parametername(std::string line);
      // Gives the name of the parameter specified in the line.
    float read_float_parameter(std::string line);
      // Reads the value of a float parameter from line.
    int read_int_parameter(std::string line);
      // Reads the value of an int parameter from line.
    std::string read_str_parameter(std::string line);
      // Reads the value of a string parameter from line.
    void read_file(std::string filename); // reads parameters from file
    float get_pixel_width(); // returns the parameter
    float get_pixel_height();
    std::string get_image_list_filename();
    std::string get_data_directory();
};

#endif
