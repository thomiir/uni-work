namespace seminar10.model;

public class StackContainer : AbstractContainer
{
    public override Task Remove()
    {
        if (_tasks.Count == 0) return null!;
        var lastTask = _tasks[^1];
        _tasks.RemoveAt(_tasks.Count - 1);
        return lastTask;
    }

    public override void Add(Task task)
    {
        _tasks.Add(task);
    }
}