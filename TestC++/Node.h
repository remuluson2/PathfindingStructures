
class Node
{
public:
	int x, y, cost;
	Node() {

	}
	Node(int x, int y) {
		this->x = x;
		this->y = y;
		cost = 0;
	}
	Node(int x, int y, int cost) {
		this->x = x;
		this->y = y;
		this->cost = cost;
	}
};