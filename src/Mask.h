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
    void read_file(std::string filename);
    float get_pixel(int pixel_x, int pixel_y);
};

#endif
