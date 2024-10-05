#ifndef OPENCLABSTRACTIONS_H
#define OPENCLABSTRACTIONS_H

#include <cl.hpp>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <math.h>
#include <utility.h>

using namespace cl;

using std::vector;
using std::string;
using std::ifstream;

extern Platform pform;
extern vector<Platform> pforms; // list of all platforms available 
extern Device device;
extern vector<Device> devices; // list of all device on chosen platform
extern Context context; // OpenCl context
extern CommandQueue queue; // Command Queue
extern const char* kernel_s; // will contain our kernal source code
extern Program program;
extern Kernel kernel;

struct Camera{
    int width;
    int height;
    float aspect_ratio;
    float viewport_h;
    float viewport_w;
    float focal_length;
    cl_float3 position;
    cl_float3 viewport_u;
    cl_float3 viewport_v;
    float fov;   
    cl_float3 look;
    cl_float3 vup;
    cl_float3 du,dv,dw;
    cl_float3 delta_u;
    cl_float3 delta_v;
    cl_float3 vp_upperleft;
    cl_float3 pixel_location;
};

inline cl_float3 cvert(vec3 v)
{
  cl_float3 r;
  r.x = v.x();
  r.y = v.y();
  r.z = v.z();

  return r;
}

inline vec3 vvert(cl_float3 c)
{
  return vec3(c.x,c.y,c.z);
}

void OpenClinit(vector<char*> files);
cl_float3* RunKernal();

void UpdateCamera(struct Camera* c);

#endif