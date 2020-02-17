// DetectorImage.h
// 
// Reads a detector image from file and returns the values of the Pixels.
// The values are integers.
// The number of rows and cols is automatically addopted from the
// header of the data file.
// It is assumed that between the values of two pixels in the data file 
// there is either a space or a line break.
//
// The indices for the pixels in the get_pixe(pixel_x, pixel_y) are compatible
// with graphical interface in the APEX Client software:
//
//    pixel_y
//      ^
//      |
//      |
//      |
//    (0,0)-------> pixel_x


#ifndef DETECTORIMAGE_H_
#define DETECTORIMAGE_H_

class DetectorImage {
  private:
    int zNRows = 0;
    int zNCols = 0;
    std::vector< std::vector< int > > zPixels;
  public:
    DetectorImage();
    ~DetectorImage();
    void read_file(std::string filename); // Reads the detecor image from file.
    int get_pixel(int pixel_x, int pixel_y); // Returns the value of a pixel.
};

#endif
