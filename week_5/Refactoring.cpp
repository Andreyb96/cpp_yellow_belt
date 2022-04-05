#include <iostream>
#include <string>
#include <vector>

class Human
{
public:
	Human(const std::string& name, const std::string& status) : 
		name(name)
		, status(status)
	{}
	virtual void Walk(const std::string& destination)
	{
		std::cout << status << ": " << name << " walks to: " << destination << std::endl;
	}

	const std::string name;
	const std::string status;
};

class Student : public Human 
{
public:
	Student(const std::string& name, const std::string& favouriteSong) :
		Human(name, "Student")
		, _favouriteSong(favouriteSong)
	{}

	void Learn()
	{
		std::cout << status << ": " << name << " learns" << std::endl;
	}

	void Walk(const std::string& destination) override
	{
		std::cout << status << ": " << name << " walks to: " << destination << std::endl;
		SingSong();
	}

	void SingSong() 
	{
		std::cout << status << ": " << name << " sings a song: " << _favouriteSong << std::endl;
	}
private:
	std::string _favouriteSong;
};


class Teacher : public Human {
public:
	Teacher(const std::string& name, const std::string& subject) :
		Human(name, "Teacher")
		, _subject(subject)
	{}

	void Teach()
	{
		std::cout << status << ": " << name << " teaches: " << _subject << std::endl;
	}
private:
	std::string _subject;
};


class Policeman : public Human
{
public:
	Policeman(const std::string& name) :
	Human(name, "Policeman")
	{}

	void Check(const Human& human) 
	{
		std::cout << status << ": " << name << " checks " << human.status << ". " << human.status << "'s name is: " << human.name << std::endl;
	}
};

void VisitPlaces(const std::shared_ptr<Human>& human, const std::vector<std::string>& places) {
	for (auto p : places) {
		human->Walk(p);
	}
}

int main() {
	auto t = std::make_shared<Teacher>("Jim", "Math");
	auto s = std::make_shared<Student>("Ann", "We will rock you");
	auto p = std::make_shared<Policeman>("Bob");

	VisitPlaces(t, { "Moscow", "London" });
	p->Check(*s);
	VisitPlaces(s, { "Moscow", "London" });
	return 0;
}
