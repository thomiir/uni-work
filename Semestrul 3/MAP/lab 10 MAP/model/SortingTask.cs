using seminar10.factory;

namespace seminar10.model;

public class SortingTask : Task
{
    private readonly SortingStrategy _strategy;
    private readonly AbstractSorter _sorter;
    private readonly int[] _vector;

    public SortingTask(string id, string description, SortingStrategy strategy, int[] vector)
        : base(id, description)
    {
        _strategy = strategy;
        _vector = vector;
        _sorter = _strategy == SortingStrategy.Bubble 
            ? new BubbleSort() 
            : new QuickSort();
    }

    public override void Execute()
    {
        _sorter.Sort(_vector);
        foreach (var i in _vector)
        {
            Console.Write(i + " ");
        }
    }
}