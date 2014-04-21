class TouchController
{
public:
	enum TouchState
	{
		NONE,CLICK,MOVE
	};
	TouchController();
	~TouchController();

	TouchState state;
	void touchBegin(int x, int y);
	void touchMove(int x, int y);
	void touchEnd(int x, int y);
private:

};
