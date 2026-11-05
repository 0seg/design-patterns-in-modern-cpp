
#include <iostream>
#include <string>
#include <map>

// Intrinsic State
struct TreeType {
    std::string name;
    std::string texture;
};

// Context: Extrinsic State + Flyweight reference
struct Tree {
    int x;
    int y;
    const TreeType* type;

    void draw() const {
        std::cout << "Tree: " << type->name
                  << " | Texture: " << type->texture
                  << " | Position: (" << x << ", " << y << ")\n";
    }
};

// Flyweight Factory
class TreeFactory {
private:
    std::map<std::string, TreeType> treeTypes_;

public:
    const TreeType* getTreeType(
        const std::string& name,
        const std::string& texture
    ) {
        std::string key = name + "_" + texture;

        auto it = treeTypes_.find(key);

        if (it != treeTypes_.end()) {
            return &it->second;
        }

        auto [newTree, inserted] = treeTypes_.emplace(
            key,
            TreeType{name, texture}
        );

        return &newTree->second;
    }

    std::size_t count() const {
        return treeTypes_.size();
    }
};

int main() {
    TreeFactory factory;

    Tree tree1{10, 20, factory.getTreeType("Oak", "oak.png")};
    Tree tree2{30, 40, factory.getTreeType("Oak", "oak.png")};
    Tree tree3{50, 60, factory.getTreeType("Pine", "pine.png")};
    Tree tree4{70, 80, factory.getTreeType("Oak", "oak.png")};

    tree1.draw();
    tree2.draw();
    tree3.draw();
    tree4.draw();

    std::cout << "\nShared objects:\n";
    std::cout << std::boolalpha;

    std::cout << "Tree 1 and Tree 2: "
              << (tree1.type == tree2.type) << '\n';

    std::cout << "Tree 1 and Tree 3: "
              << (tree1.type == tree3.type) << '\n';

    std::cout << "Tree 1 and Tree 4: "
              << (tree1.type == tree4.type) << '\n';

    std::cout << "\nUnique tree types: "
              << factory.count() << '\n';

    return 0;
}
