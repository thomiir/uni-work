namespace seminar10.decorator;
using model;

public interface ITaskRunner
{
    void ExecuteOneTask();
    void ExecuteAll();
    void AddTask(Task t);
    bool HasTask();
}