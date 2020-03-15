#pragma once
#include <iostream>
#include <string>
#include <cmath>
#define MAX 9999

int maps(char *map,int n,char a);
int minimum(int *t,int n);
int string_to_int(string s);

void _init(int** graph, char* map,int n);
void add_edges(int** graph, char* map,int n);
void Dijkstra(int** graph, char* map,int n);
void Floyd(int** graph, char* map,int n);
void Prim(int** graph, char* map,int n);
