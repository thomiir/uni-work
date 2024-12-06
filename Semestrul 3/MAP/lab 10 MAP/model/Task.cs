namespace seminar10.model;

public abstract class Task(string id, string description)
{
    protected string Id { get; } = id;

    protected string Description { get; } = description;

    public abstract void Execute();

    public override string ToString()
    {
        return "Task{" +
               "id='" + Id + '\'' +
               ", description='" + Description + '\'' +
               '}';
    }

    private bool Equals(Task other)
    {
        return Id == other.Id && Description == other.Description;
    }

    public override bool Equals(object? obj)
    {
        if (obj is null) return false;
        if (ReferenceEquals(this, obj)) return true;
        return obj.GetType() == GetType() && Equals((Task)obj);
    }

    public override int GetHashCode()
    {
        return HashCode.Combine(Id, Description);
    }
}