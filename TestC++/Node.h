#pragma once
class Node
{
public:
	int x, y, cost, priority;
	Node() {
		this->x = 0;
		this->y = 0;
		this->cost = 0;
		this->priority = 0;
	}
	Node(int x, int y) {
		this->x = x;
		this->y = y;
		this->cost = 0;
		this->priority = 0;
	}
	Node(int x, int y, int cost) {
		this->x = x;
		this->y = y;
		this->cost = cost;
		this->priority = 0;
	}
};