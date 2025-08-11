#ifndef MATERIAL_H
#define MATERIAL_H

class Material
{
public:
    virtual ~Material() = default;

    virtual bool scatter(const Ray &r_in, const HitRecord &rec, Color &attenuation, Ray &scattered) const
    {
        return false;
    }
};

class Lambertian : public Material
{
public:
    Lambertian(const Color &albedo) : albedo(albedo) {}

    bool scatter(const Ray &r_in, const HitRecord &rec, Color &attenuation, Ray &scattered) const override
    {
        auto scatter_direction = rec.normal + random_unit_vector();

        if (scatter_direction.near_zero())
            scatter_direction = rec.normal;

        scattered = Ray(rec.p, scatter_direction);
        attenuation = albedo;
        return true;
    }

private:
    Color albedo;
};

class Metal : public Material
{
public:
    Metal(const Color &albedo) : albedo(albedo) {}

    bool scatter(const Ray &r_in, const HitRecord &rec, Color &attenuation, Ray &scattered) const override
    {
        Vec3 reflected = reflect(r_in.direction(), rec.normal);
        scattered = Ray(rec.p, reflected);
        attenuation = albedo;
        return true;
    }

private:
    Color albedo;
};

#endif