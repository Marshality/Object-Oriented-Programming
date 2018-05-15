//
// Created by Marshal on 12/05/2018.
//

#ifndef LAB03_EDGE_H
#define LAB03_EDGE_H

class Edge {
private:
    int a, b;

public:
    Edge() = default;

    Edge(int a, int b) {
        this->a = a;
        this->b = b;
    }

    int get_a() { return this->a; }

    int get_b() { return this->b; }
};

#endif //LAB03_EDGE_H
