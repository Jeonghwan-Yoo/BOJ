#include <iostream>

using namespace std;

pair<char, char> children[26];

enum Order
{
    None = 0,
    Preorder,
    Inorder,
    Postorder,
};

void Traversal(int root, Order order)
{
    if (root < 0)
    {
        return;
    }
    if (order == Order::Preorder)
        cout << static_cast<char>(root + 'A');
    Traversal(children[root].first - 'A', order);
    if (order == Order::Inorder)
        cout << static_cast<char>(root + 'A');
    Traversal(children[root].second - 'A', order);
    if (order == Order::Postorder)
        cout << static_cast<char>(root + 'A');
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        char node, left, right;
        cin >> node >> left >> right;
        if (left != '.')
            children[node - 'A'].first = left;
        else
            children[node - 'A'].first = 0;
        if (right != '.')
            children[node - 'A'].second = right;
        else
            children[node - 'A'].second = 0;
    }
    Traversal(0, Order::Preorder);
    cout << '\n';
    Traversal(0, Order::Inorder);
    cout << '\n';
    Traversal(0, Order::Postorder);

    return 0;
}