namespace seminar10.model;

public class QueueContainer : AbstractContainer
{
    public override Task Remove()
    {
        if (_tasks.Count == 0)
            return null!;
        var task = _tasks[0];
        _tasks.RemoveAt(0);
        return task;
    }

    public override void Add(Task task)
    {
        _tasks.Add(task);
    }
}