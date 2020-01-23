#include "sphere.h"
#include "ray.h"

// Determine if the ray intersects with the sphere
Hit Sphere::Intersection(const Ray& ray, int part) const
{
    //Initialize t values
    double t = 0;
    double t1 = 0;
    double t0 = 0;

    //Get the variables for quadratic formula
    double a = dot(ray.direction, ray.direction);
    double b = 2 * dot(ray.direction, ray.endpoint - center);
    double c = dot(ray.endpoint - center, ray.endpoint - center) - (radius * radius);

    //Calculate discriminant
    double discriminant = (b*b) - (4 * a * c);
    if (discriminant < 0) {
      t = 0;
    }
    else if (discriminant == 0) {
      t0 = (-b - sqrt(discriminant))/(2*a);
      t1 = t0;
      t = t0;
    }
    else {
      t0 = (-b + sqrt(discriminant))/(2*a);
      t1 = (-b - sqrt(discriminant))/(2*a);

      if (t0 > small_t && t0 < t1) {
        t = t0;
      }
      else if (t1 > small_t && t1 < t0) {
        t = t1;
      }
    }
    return {this, t, 0};
}

vec3 Sphere::Normal(const vec3& point, int part) const
{
    vec3 normal;
    TODO; // compute the normal direction
    return normal;
}

Box Sphere::Bounding_Box(int part) const
{
    Box box;
    TODO; // calculate bounding box
    return box;
}
