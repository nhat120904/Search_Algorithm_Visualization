#pragma once
#include "Scenario.h"
#include "SearchAlgorithm.h"
#include "BFS.h"
#include <thread>
#include <chrono>
#include "DFS.h"
#include "GBFS.h"
#include "AStar.h"
#include "Dijkstra.h"
#include "IDDFS.h"


namespace Project1 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class GridForm : public System::Windows::Forms::Form
    {
    private:
        Scenario* myScenario;
        System::Threading::Thread^ bfsThread;


    public:

        GridForm(Scenario* scenario, int method)
        {
            myScenario = scenario;
            numRows = myScenario->grid.rows;
            numCols = myScenario->grid.cols;
            searchMethod = method;
            InitializeForm();
            gridImage = gcnew Bitmap(numCols * blockSize, numRows * blockSize);
        }


        ~GridForm()
        {
            delete bfs;
            delete dfs;
            delete astar;
            delete gbfs;
            delete iddfs;
            delete dijkstra;
        }

        void StartBFSVisualization()
        {
            // Create a thread to run the BFS search
            bfsThread = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(this, &GridForm::RunBFS));
            bfsThread->Start();
        }

    protected:
        void InitializeForm()
        {
            this->Text = "Robot Navigation";
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(numCols * blockSize, numRows * blockSize);
            this->DoubleBuffered = true;
            this->ResumeLayout(false);
            this->PerformLayout();
            StartBFSVisualization();
        }


        void DrawScenario(Graphics^ g, int numRows, int numCols, int blockSize, Scenario* myScenario)
        {

            for (int row = 0; row < numRows; ++row)
            {
                for (int col = 0; col < numCols; ++col)
                {
                    int x = col * blockSize;
                    int y = row * blockSize;

                    int value = myScenario->grid.map[row][col];
                    Color blockColor = Color::Gray;

                    if (value == 1)
                    {
                        SolidBrush^ fillBrush = gcnew SolidBrush(blockColor);
                        g->FillRectangle(fillBrush, x, y, blockSize, blockSize);
                    }
                    else if (value == 3)
                    {
                        SolidBrush^ fillBrush = gcnew SolidBrush(Color::Blue);
                        g->FillRectangle(fillBrush, x, y, blockSize, blockSize);
                    }
                    else if (value == 4)
                    {
                        SolidBrush^ fillBrush = gcnew SolidBrush(Color::LightPink);
                        g->FillRectangle(fillBrush, x, y, blockSize, blockSize);
                    }
                    Pen^ borderPen = gcnew Pen(Color::Black);
                    g->DrawRectangle(borderPen, x, y, blockSize, blockSize);
                }
            }

            for (auto& goal : myScenario->goals.goals)
            {
                SolidBrush^ fillGoalState = gcnew SolidBrush(Color::Green);
                g->FillRectangle(fillGoalState, goal.y * blockSize, goal.x * blockSize, blockSize, blockSize);
            }
            SolidBrush^ fillInitialState = gcnew SolidBrush(Color::Red);
            g->FillRectangle(fillInitialState, myScenario->initialState.y * blockSize, myScenario->initialState.x * blockSize, blockSize, blockSize);
        }

        void RunBFS()
        {
            Path path;
            Path storeNode;
            switch (searchMethod)
            {
            case 1:
                bfs = new BFS(*myScenario);
                bfs->Search();
                path = bfs->path;
                storeNode = bfs->storeNode;
                break;
            case 2:
                dfs = new DFS(*myScenario);
                dfs->Search();
                path = dfs->path;
                storeNode = dfs->storeNode;
                break;
            case 5:
                astar = new AStar(*myScenario);
                astar->Search();
                path = astar->path;
                storeNode = astar->storeNode;
                break;
            case 3:
                iddfs = new IDDFS(*myScenario);
                iddfs->Search();
                path = iddfs->path;
                storeNode = iddfs->storeNode;
                break;
            case 4:
                dijkstra = new Dijkstra(*myScenario);
                dijkstra->Search();
                path = dijkstra->path;
                storeNode = dijkstra->storeNode;
                break;
            case 6:
                gbfs = new GBFS(*myScenario);
                gbfs->Search();
                path = gbfs->path;
                storeNode = gbfs->storeNode;
            default:
                break;
            };

            // Iterate through the BFS steps and update the display
            for (size_t i = 1; i < storeNode.cells.size(); i++)
            {
                myScenario->grid.map[storeNode.cells[i].x][storeNode.cells[i].y] = 4;
                this->Invalidate(); // Request a repaint

                System::Threading::Thread::Sleep(10); // Control visualization speed
            }


            for (size_t i = 1; i < path.cells.size(); i++)
            {
                myScenario->grid.map[path.cells[i].x][path.cells[i].y] = 3;
                this->Invalidate(); // Request a repaint

                System::Threading::Thread::Sleep(10); // Control visualization speed
            }


        }



        void OnPaint(PaintEventArgs^ e) override
        {
            __super::OnPaint(e);
            Graphics^ g = e->Graphics;
            DrawScenario(g, numRows, numCols, blockSize, myScenario);
        }

    private:
        int numRows;
        int numCols;
        int blockSize = 20;
        int searchMethod;
        BFS* bfs;
        DFS* dfs;
        AStar* astar;
        IDDFS* iddfs;
        Dijkstra* dijkstra;
        GBFS* gbfs;
        Cell* currentCell;
        Bitmap^ gridImage;
        Path* storeNode;
        Color GetRandomColor()
        {
            Random^ rand = gcnew Random();
            int r = rand->Next(256);
            int g = rand->Next(256);
            int b = rand->Next(256);
            return Color::FromArgb(255, r, g, b);
        }
    };


}

