#include<iostream>
#include<fstream>

struct Particle {
    double x,y;
    double vx, vy;

    Particle(double px, double py, double pvx, double pvy)
        : x(px), y(py), vx(pvx), vy(pvy) {}
};

int main()
{
    Particle p1 {0.2, 0.14, 0.1, 0.1};
    Particle p2 {1.0, 0.0, -0.1, 0.0};

    double deltatime = 0.01;
    int step = 0;

    std::ofstream outfile("data.txt");

    for (; step < 100; ++step)
        {
            p1.x += p1.vx * deltatime;
            p1.y += p1.vy * deltatime;
            p2.x += p2.vx * deltatime;
            p2.y += p2.vy * deltatime;

            
            outfile << "Step " << step << ": "
                      << "p1(" << p1.x << ", " << p1.y << ") "
                      << "p2(" << p2.x << ", " << p2.y << ")\n";

        }

        outfile.close();
}
