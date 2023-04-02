#include <iostream>
#include <cmath>

class Shape {
   public:
      std::string ShapeName = "Shape";
      virtual double surfaceArea() = 0; // Pure virtual function is declared as follows.
      virtual std::string getSuccessorName() = 0;


   protected:
      double s;

};

class Cylinder: public Shape {
public:
    std::string ShapeName;
    Cylinder(double r, double h) : m_radius(r), m_height(h) {
        ShapeName = "Cylinder";
    }
    std::string getSuccessorName(){
        return ShapeName;
    }

    double surfaceArea() {
        s = (double)2 * (double)M_PI * m_radius * (m_height + m_radius);
        return s;
    }
    void ShowS(bool m_displayIntFirst);


private:
    double s;
    double m_radius;
    double m_height;
};

class Cube: public Shape {
public:
    std::string ShapeName;
    Cube(double s) : m_side(s) {
        ShapeName = "Cube";
    }
    std::string getSuccessorName(){
        return ShapeName;
    }
    double surfaceArea() {
        s = 6 * pow(m_side, 2);
        return s;
    }
    void ShowS(bool m_displayIntFirst);

private:
    double s;
    double m_side;
};

class Tetrahedron: public Shape {
public:
    std::string ShapeName;
    Tetrahedron(double s) : m_side(s) {
        ShapeName = "Tetrahedron";
    }
    std::string getSuccessorName(){
        return ShapeName;
    }
    double surfaceArea() {
        s = sqrt(3) * pow(m_side, 2);
        return s;
    }
    void ShowS(bool m_displayIntFirst);

private:
    double s;
    double m_side;
};

class Parallelepiped: public Shape {
public:
    std::string ShapeName;
    Parallelepiped(double l, double w, double h) : m_length(l), m_width(w), m_height(h) {
        ShapeName = "Parallelepiped";
    }
    std::string getSuccessorName(){
        return ShapeName;
    }
    double surfaceArea() {
        s = 2 * (m_length * m_width + m_length * m_height + m_width * m_height);
        return s;
    }
    void ShowS(bool m_displayIntFirst);

private:
    double s;
    double m_length;
    double m_width;
    double m_height;
};

class Sphere : public Shape{
public:
    std::string ShapeName;
    Sphere(double r) : m_radius(r) {
        ShapeName = "Sphere";
    }
    std::string getSuccessorName(){
        return ShapeName;
    }
    double surfaceArea() {
        s = 4 * M_PI * pow(m_radius, 2);
        return s;
    }
    void ShowS(bool m_displayIntFirst);

private:
    double s;
    double m_radius;
};


inline void Sphere::ShowS(bool m_displayIntFirst)
{
    if (m_displayIntFirst)
        std::cout << getSuccessorName() << " s = " << surfaceArea() << '\n';
    else // або спочатку виводимо double
        std::cout << "Value s = " << surfaceArea() << '\n';
}

inline void Parallelepiped::ShowS(bool m_displayIntFirst)
{
    if (m_displayIntFirst)
        std::cout << getSuccessorName() << " s = " << surfaceArea() << '\n';
    else // або спочатку виводимо double
        std::cout << "Value s = " << surfaceArea() << '\n';
}

inline void Tetrahedron::ShowS(bool m_displayIntFirst)
{
    if (m_displayIntFirst)
        std::cout << getSuccessorName() << " s = " << surfaceArea() << '\n';
    else // або спочатку виводимо double
        std::cout << "Value s = " << surfaceArea() << '\n';
}

inline void Cube::ShowS(bool m_displayIntFirst)
{
    if (m_displayIntFirst)
        std::cout << getSuccessorName() << " s = " << surfaceArea() << '\n';
    else // або спочатку виводимо double
        std::cout << "Value s = " << surfaceArea() << '\n';
}



int main() {

    Cylinder c(3, 5);
    c.ShowS(true);

    Cube cu(3);
    cu.ShowS(true);

    Tetrahedron t(4);
    t.ShowS(true);

    Parallelepiped p(2, 3, 4);
    p.ShowS(true);

    Sphere s(2);
    s.ShowS(true);

    return 0;
}