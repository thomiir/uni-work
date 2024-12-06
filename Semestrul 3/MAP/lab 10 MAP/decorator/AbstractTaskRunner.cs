﻿namespace seminar10.decorator;
using model;

public abstract class AbstractTaskRunner(ITaskRunner taskRunner) : ITaskRunner
{
    public virtual void ExecuteOneTask()
    {
        taskRunner.ExecuteOneTask();
    }

    public virtual void ExecuteAll()
    {
        while (HasTask())
        {
            taskRunner.ExecuteOneTask();
        }
    }

    public virtual void AddTask(Task t)
    {
        taskRunner.AddTask(t);
    }

    public virtual bool HasTask()
    {
        return taskRunner.HasTask();
    }
}