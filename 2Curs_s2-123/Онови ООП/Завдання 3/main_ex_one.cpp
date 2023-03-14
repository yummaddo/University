#include <iostream>
#include <cmath>

class Shape {
   public:
      std::string ShapeName = "Shape";
      virtual double surfaceArea() = 0; // Pure virtual function is declared as follows.
      virtual std::string getSuccessorName() = 0;

      friend class Show;
    
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

private:
    double s;
    double m_radius;
};


class Show
{
private:
    bool m_displayIntFirst;
public:
    Show(bool displayIntFirst) { m_displayIntFirst = displayIntFirst; }

    void ShowS(Shape &value)
    {
        if (m_displayIntFirst)
            std::cout << value.getSuccessorName() << " s = " << value.surfaceArea() << '\n';
        else // або спочатку виводимо double
            std::cout << "Value s = " << value.surfaceArea() << '\n';
    }
};


int main() {
    Show show(true);

    Cylinder c(3, 5);
    show.ShowS(c);

    Cube cu(3);
    show.ShowS(cu);

    Tetrahedron t(4);
    show.ShowS(t);

    Parallelepiped p(2, 3, 4);
    show.ShowS(p);

    Sphere s(2);
    show.ShowS(s);

    return 0;
}