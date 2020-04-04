#ifndef MASKMAKER_H_
#define MASKMAKER_H_

class MaskMaker {
  private:
  public:
    MaskMaker();
    ~MaskMaker();
    void make_mask(std::string data_directory,
                   std::string list_filename,
                   std::string output_filename);
    void multiply_masks(std::string input_filename_1,
                        std::string input_filename_2,
                        std::string output_filename);
    void invert_mask(std::string input_filename,
                     std::string output_filename);
};

#endif
