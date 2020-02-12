#ifndef GEOMETRY_H_
#define GEOMETRY_H_

class Geometry {
  private:
    float zDetectorDistance = 0.0;
    float zPixelWidth = 0.0;
    float zPixelHeight = 0.0;
    float zCentrePixelX = 0.0;
    float zCentrePixelY = 0.0;
    float zTwotheta = 0.0;
  public:
    Geometry();
    ~Geometry();
    void set_detector_distance(float detector_distance);
    float get_detector_distance();
    void set_pixel_width(float pixel_width);
    float get_pixel_width();
    void set_pixel_height(float pixel_height);
    float get_pixel_height();
    void set_centre_pixel_x(float centre_pixel_x);
    float get_centre_pixel_x();
    void set_centre_pixel_y(float centre_pixel_y);
    float get_centre_pixel_y();
    void set_twotheta(float twotheta);
    float get_twotheta();
    float calculate_powderangle(int pixel_x, int pixel_y);
};

#endif
