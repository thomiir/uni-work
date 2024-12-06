namespace seminar10.decorator;
using model;

public class AbstractTaskRunner(ITaskRunner taskRunner) : ITaskRunner
{
    public virtual void ExecuteOneTask()
    {
        taskRunner.ExecuteOneTask();
    }

    public void ExecuteAll()
    {
        while (HasTask())
        {
            taskRunner.ExecuteOneTask();
        }
    }

    public void AddTask(Task t)
    {
        taskRunner.AddTask(t);
    }

    public bool HasTask()
    {
        return taskRunner.HasTask();
    }
}