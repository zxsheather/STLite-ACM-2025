#include <iostream>
#include <cassert>
#include "../../src/map.hpp"

int main() {
    sjtu::map<int, int> testMap;
    
    // 构建最小化的特殊结构树，确保删除后触发问题
    int values[] = {50, 30, 70, 20, 40, 35, 45};
    for (int val : values) {
        testMap[val] = val;
        std::cout << "插入: " << val << std::endl;
    }
    
    std::cout << "树大小: " << testMap.size() << std::endl;
    testMap.printTree(); // 打印树结构
    
    // 核心测试：删除节点30（有两个子节点）
    // 这将触发节点替换和树平衡调整
    std::cout << "删除节点30（有两个子节点）...\n";
    testMap.erase(testMap.find(30));
    testMap.printTree();

    testMap.erase(testMap.find(35));
    testMap.printTree();
    testMap.erase(testMap.find(20));
    testMap.printTree();
    testMap.erase(testMap.find(40));
    testMap.printTree();
    
    std::cout << "删除后树大小: " << testMap.size() << std::endl;
    
    return 0;
}