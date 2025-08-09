#include "rtweekend.h"

#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"

int main(int, char **)
{

    HittableList world;

    world.add(make_shared<Sphere>(Point3(0.0, -100.5, -1.0), 100.0));

    world.add(make_shared<Sphere>(Point3(-0.1, 0.0, -1.2), 0.5));
    world.add(make_shared<Sphere>(Point3(-1.0, 0.0, -1.0), 0.5));
    world.add(make_shared<Sphere>(Point3(1.1, 0.0, -1.0), 0.5));

    Camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 400;
    cam.samples_per_pixel = 100;
    cam.max_depth = 50;

    cam.render(world);
}
