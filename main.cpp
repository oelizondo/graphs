//
//  main.cpp
//  tarea_grafos
//
//  Created by Oscar Elizondo on 11/10/15.
//  Copyright © 2015 Oscar Elizondo. All rights reserved.
//

//prof: 123865479
//Anch: 124735896
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void breadth(int nodos, int statusArray[20], int matriz[20][20]){
    queue<int> breadthQueue;
    breadthQueue.push(0);
    statusArray[0] = 1;

    while (!breadthQueue.empty()) {

        int dato = breadthQueue.front();
        breadthQueue.pop();
        statusArray[dato] = 2;
        cout << dato + 1 << endl;

        for (int i = 0 ; i < nodos ; i++) {
            if (matriz[dato][i] == 1 && statusArray[i] != 1 && statusArray[i] != 2) {
                breadthQueue.push(i);
                statusArray[i] = 2;
            }
        }
    }

}

void depth(int nodos, int boolArray[20], int matriz[20][20]){
    stack<int> depthStack;
    depthStack.push(0);
    boolArray[0] = true;

    while(!depthStack.empty()) {

        int dato = depthStack.top();
        depthStack.pop();
        boolArray[dato] = false;
        cout << dato + 1 << endl;

        for (int i = 0 ; i < nodos ; i++) {
            if (matriz[dato][i] == false && boolArray[i] != true) {
                depthStack.push(i);
                boolArray[i] = true;
            }
        }
    }

}

int main () {
    int nodos;
    int dato;
    int matriz[20][20];
    bool boolArray[20];    //Decalara el arreglo para la función depth
    int statusArray[20];   //Decalara el arreglo para la función breadth

    cin >> nodos;

    //Llena los arreglos con su status correspondiente
    for (int i = 0 ; i  < nodos ; i ++) {
        boolArray[i] = false;
        statusArray[i] = 0;
    }

    //Llena la matriz
    for (int i = 0; i < nodos; i++) {
        for (int j = 0 ; j < nodos; j++) {
            cin >> dato;
            matriz[i][j] = dato;
        }
    }

    breadth(nodos, statusArray, matriz);
    depth(nodos, statusArray, matriz);

    return 0;
}
