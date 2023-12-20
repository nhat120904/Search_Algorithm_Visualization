#include "MyForm.h"
#include <iostream>
#include <Windows.h> // For Sleep function
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "SearchAlgorithm.h"

using namespace std;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace Project1;


int main(int argc, char* argv[])
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    string search, filename, method;
    search = (string)argv[0];
    filename = (string)argv[1];
    method = (string)argv[2];

    ifstream Input(filename);
    if (Input.fail())
    {
        std::cout << "failed to open file" << std::endl;
        return -1;
    }
    Goal goals;
    Walls walls;
    int n, m, x, y, x0, y0, w, h;
    char leftBracket, comma, rightBracket;
    Input >> leftBracket >> n >> comma >> m >> rightBracket;
    Input >> leftBracket >> y0 >> comma >> x0 >> rightBracket;
    Cell initialState(x0, y0);
    char pipe;
    std::string goalLine;
    std::getline(Input, goalLine);
    std::getline(Input, goalLine);
    std::istringstream iss(goalLine);
    std::string goalStr;
    while (std::getline(iss, goalStr, '|')) {
        std::istringstream goalIss(goalStr);
        char openParen, comma, closeParen;
        int x, y;
        goalIss >> openParen >> x >> comma >> y >> closeParen;
        Cell cell(y, x);
        goals.addGoal(cell);
    }
    std::string wallLine;
    while (std::getline(Input, wallLine)) {
        int x, y, w, h;
        if (sscanf_s(wallLine.c_str(), "(%d,%d,%d,%d)", &x, &y, &w, &h) == 4) {
            walls.addWall(x, y, w, h);
        }
    }
    Grid grid(n, m, walls);
    grid.Initialize(n, m);
    Input.close();
    Scenario* myScenarioInstance = new Scenario(grid, initialState, goals);
    MyForm^ form = gcnew MyForm(myScenarioInstance); // Pass the Scenario instance to the MyForm constructor

    Application::Run(form);
    return 0;
}


