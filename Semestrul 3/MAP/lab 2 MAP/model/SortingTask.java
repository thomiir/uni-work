package sem1_2.model;

import sem1_2.factory.SortingStrategy;

public class SortingTask extends Task{


    public SortingStrategy strategy;
    public AbstractSorter sorter;
    public int[] vector;

    public SortingTask(String id, String description, SortingStrategy strategy, int[] vector) {
        super(id, description);
        this.strategy = strategy;
        this.vector = vector;
        if (strategy == SortingStrategy.BUBBLE) {
            sorter = new BubbleSort();
        }
        else {
            sorter = new QuickSort();
        }
    }

    @Override
    public void execute(){
        sorter.sort(vector);
        for (int j : vector) {
            System.out.print(j + " ");
        }
    }
}
