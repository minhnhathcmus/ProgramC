#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool checkValidChildrenPassword(string password);
bool verifyPassword(string password, string repassword);
int countSpaces(string s);