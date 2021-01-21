#ifndef CAT_H_
#define CAT_H_

class Cat {
private:
	bool happy;
public:
	bool getHappy();
	void setHappy(bool val);
	void speak();
	void jump();
	Cat();
	~Cat();
};

#endif