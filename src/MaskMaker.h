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
};

#endif
