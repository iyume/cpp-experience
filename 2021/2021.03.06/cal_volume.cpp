#include <iostream>
using namespace std;

struct Cube
{
    float length;
    float width;
    float height;
};

class CubeModel
{
    float length;
    float width;
    float height;

public:
    float volume; // set public attr
    CubeModel(Cube c);
    int get_volume()
    {
        return volume;
    }
};

CubeModel::CubeModel(Cube c)
{
    length = c.length;
    width = c.width;
    height = c.height;
    volume = length * width * height;
};

int main()
{
    Cube *c;
    CubeModel *cube;
    c = new Cube[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> c[i].length;
        cin >> c[i].width;
        cin >> c[i].height;
    };
    cube = new CubeModel[3]{c[0], c[1], c[2]};
    delete[] c;
    for (int i = 0; i < 3; i++)
    {
        if (i == 2)
        {
            cout << cube[i].volume;
            break;
        }
        cout << cube[i].volume << endl;
    }
    return 0;
}
