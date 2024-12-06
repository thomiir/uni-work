namespace seminar10.model;

public abstract class AbstractContainer : IContainer
{
    protected readonly List<Task> _tasks = [];

    public abstract Task Remove();

    public abstract void Add(Task task);

    public int Size()
    {
        return _tasks.Count;
    }

    public bool IsEmpty()
    {
        return _tasks.Count == 0;
    }
}