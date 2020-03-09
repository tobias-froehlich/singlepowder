#ifndef MASK_H_
#define MASK_H_

class Mask {
  private:
    std::vector< std::vector < float > > zPixels{};
    int zNRows = 0;
    int zNCols = 0;
  public:
    Mask();
    ~Mask();
    void init(int num_of_cols, int num_of_rows);
    void read_file(std::string filename);
    int get_num_of_cols();
    int get_num_of_rows();
    float get_pixel(int pixel_x, int pixel_y);
    void set_pixel(int pixel_x, int pixel_y, float value);
    void write_file(std::string filename);
};

#endif
