#include <map>
#include <string>
#include <tuple>
#include <iostream>
#include <cassert>

enum class TaskStatus : int
{
	NEW,
	IN_PROGRESS,
	TESTING,
	DONE
};

TaskStatus Next(TaskStatus currentStatus)
{
	if (currentStatus == TaskStatus::DONE)
	{
		return currentStatus;
	}
	return TaskStatus(static_cast<int>(currentStatus) + 1);
}

using TasksInfo = std::map<TaskStatus, int>;

class TeamTasks {
public:
	const TasksInfo& GetPersonTasksInfo(const std::string& person) const
	{
		auto it = _devTasks.find(person);
		if (it == _devTasks.end())
		{
			return TasksInfo();
		}
		return it->second;
	}

	void AddNewTask(const std::string& person)
	{
		auto itPerson = _devTasks.find(person);
		if (itPerson == _devTasks.end())
		{
			_devTasks.insert({ person, {{TaskStatus::NEW, 1}} });
			for (auto i = 1; i < 4; i++)
			{
				_devTasks.at(person).insert({ static_cast<TaskStatus>(i), 0 });
			}

			return;
		}

		auto itNewTasks = itPerson->second.find(TaskStatus::NEW);
		itNewTasks->second++;
	}

	std::tuple<TasksInfo, TasksInfo> PerformPersonTasks(
		const std::string& person, int task_count)
	{
		auto& tasksInfo = _devTasks.find(person)->second;
		auto untouchedTasks = tasksInfo;
		TasksInfo updatedTasks;

		for (auto i = 0; i < 4; i++)
		{
			updatedTasks.insert({ static_cast<TaskStatus>(i), 0 });
		}

		int counter = 0;

		for (const auto& elem : tasksInfo)
		{
			auto prevIt = tasksInfo.find(elem.first);
			auto postIt = tasksInfo.find(Next(elem.first));
			while (prevIt->second != 0)
			{
				prevIt->second--;
				postIt->second++;
				updatedTasks.at(postIt->first)++;
				untouchedTasks.at(prevIt->first)--;
				counter++;
				if (counter == task_count)
				{
					break;
				}
			}
			if (counter == task_count)
			{
				break;
			}
		}

		return { updatedTasks, untouchedTasks };
	}
private:
	std::map<std::string, TasksInfo> _devTasks;
};

int main() {
	TeamTasks tasks;
	tasks.AddNewTask("Ilia");
	for (int i = 0; i < 3; ++i) {
		tasks.AddNewTask("Ivan");
	}
	assert(tasks.GetPersonTasksInfo("Ilia").at(TaskStatus::NEW) == 1);
	assert(tasks.GetPersonTasksInfo("Ilia").at(TaskStatus::IN_PROGRESS) == 0);
	assert(tasks.GetPersonTasksInfo("Ilia").at(TaskStatus::TESTING) == 0);
	assert(tasks.GetPersonTasksInfo("Ilia").at(TaskStatus::DONE) == 0);

	assert(tasks.GetPersonTasksInfo("Ivan").at(TaskStatus::NEW) == 3);
	assert(tasks.GetPersonTasksInfo("Ivan").at(TaskStatus::IN_PROGRESS) == 0);
	assert(tasks.GetPersonTasksInfo("Ivan").at(TaskStatus::TESTING) == 0);
	assert(tasks.GetPersonTasksInfo("Ivan").at(TaskStatus::DONE) == 0);

	TasksInfo updated_tasks, untouched_tasks;

	std::tie(updated_tasks, untouched_tasks) =
		tasks.PerformPersonTasks("Ivan", 2);

	assert(updated_tasks.at(TaskStatus::NEW) == 0);
	assert(updated_tasks.at(TaskStatus::IN_PROGRESS) == 2);
	assert(updated_tasks.at(TaskStatus::TESTING) == 0);
	assert(updated_tasks.at(TaskStatus::DONE) == 0);

	assert(untouched_tasks.at(TaskStatus::NEW) == 1);
	assert(untouched_tasks.at(TaskStatus::IN_PROGRESS) == 0);
	assert(untouched_tasks.at(TaskStatus::TESTING) == 0);
	assert(untouched_tasks.at(TaskStatus::DONE) == 0);

	std::tie(updated_tasks, untouched_tasks) =
		tasks.PerformPersonTasks("Ivan", 2);

	assert(updated_tasks.at(TaskStatus::NEW) == 0);
	assert(updated_tasks.at(TaskStatus::IN_PROGRESS) == 1);
	assert(updated_tasks.at(TaskStatus::TESTING) == 1);
	assert(updated_tasks.at(TaskStatus::DONE) == 0);

	assert(untouched_tasks.at(TaskStatus::NEW) == 0);
	assert(untouched_tasks.at(TaskStatus::IN_PROGRESS) == 1);
	assert(untouched_tasks.at(TaskStatus::TESTING) == 0);
	assert(untouched_tasks.at(TaskStatus::DONE) == 0);

	return 0;
}