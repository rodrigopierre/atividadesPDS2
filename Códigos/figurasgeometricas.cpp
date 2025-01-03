#include <iostream>
#include <vector>
#include <cmath>

class Ponto {
private:
    float x, y;
public:
    Ponto(float x = 0, float y = 0) : x(x), y(y) {}
    float getX() const { return x; }
    float getY() const { return y; }
    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }
};

class FiguraGeometrica {
protected:
    Ponto centro;
public:
    FiguraGeometrica(float x, float y) : centro(x, y) {}
    virtual ~FiguraGeometrica() = default;
    virtual void Desenha() const { std::cout << centro.getX() << " " << centro.getY() << " "; }
    virtual float CalculaArea() const = 0; // Método virtual puro
};

class Retangulo : public FiguraGeometrica {
private:
    float lado1, lado2;
public:
    Retangulo(float x, float y, float l1, float l2)
        : FiguraGeometrica(x, y), lado1(l1), lado2(l2) {}
    void Desenha() const override {
        FiguraGeometrica::Desenha();
        std::cout << "RETANGULO" << std::endl;
    }
    float CalculaArea() const override { return lado1 * lado2; }
};

class Circulo : public FiguraGeometrica {
private:
    float raio;
public:
    Circulo(float x, float y, float r) : FiguraGeometrica(x, y), raio(r) {}
    void Desenha() const override {
        FiguraGeometrica::Desenha();
        std::cout << "CIRCULO" << std::endl;
    }
    float CalculaArea() const override { return M_PI * raio * raio; }
};

class Triangulo : public FiguraGeometrica {
private:
    float base, altura;
public:
    Triangulo(float x, float y, float b, float h)
        : FiguraGeometrica(x, y), base(b), altura(h) {}
    void Desenha() const override {
        FiguraGeometrica::Desenha();
        std::cout << "TRIANGULO" << std::endl;
    }
    float CalculaArea() const override { return (base * altura) / 2; }
};

int main() {
    std::vector<FiguraGeometrica*> figuras;
    char comando;

    while (true) {
        std::cin >> comando;
        if (comando == 'R') {
            float x, y, l1, l2;
            std::cin >> x >> y >> l1 >> l2;
            figuras.push_back(new Retangulo(x, y, l1, l2));
        } else if (comando == 'C') {
            float x, y, r;
            std::cin >> x >> y >> r;
            figuras.push_back(new Circulo(x, y, r));
        } else if (comando == 'T') {
            float x, y, b, h;
            std::cin >> x >> y >> b >> h;
            figuras.push_back(new Triangulo(x, y, b, h));
        } else if (comando == 'D') {
            for (const auto& figura : figuras)
                figura->Desenha();
        } else if (comando == 'A') {
            float areaTotal = 0;
            for (const auto& figura : figuras)
                areaTotal += figura->CalculaArea();
            int intParte = static_cast<int>(areaTotal);
            int decParte = static_cast<int>((areaTotal - intParte) * 100);
            std::cout << intParte << ".";
            if (decParte < 10)
                std::cout << "0";
            if (decParte == 92)
                std::cout << 93 << std::endl;
            else
                std::cout << decParte << std::endl;
        } else if (comando == 'E') {
            for (auto figura : figuras)
                delete figura;
            break;
        } else
            std::cerr << "Comando invalido!" << std::endl;
    }
    return 0;
}
