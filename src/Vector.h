#ifndef VEC_H_
#define VEC_H_

class Vector {
  private:
    float zComponent1 = 0.0;
    float zComponent2 = 0.0;
    float zComponent3 = 0.0;
  public:
    Vector();
    ~Vector();
    void set_components(float component1, float component2, float component3);
    float get_component1();
    float get_component2();
    float get_component3();
    Vector operator + (Vector right);
};


#endif
