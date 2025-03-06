using System;
using static System.Console;
using System.Collections.Specialized;
using System.Collections.ObjectModel;

public class Program {
    public static void data_changed(object sender,
      NotifyCollectionChangedEventArgs e) {
        Write($"{e.Action.ToString()}: ");
        if (e.OldItems != null) {
            Write($"starting old index: {e.OldStartingIndex}, ");
            Write($"old items: ");
            foreach (var item in e.OldItems) WriteLine($"{item} "); 
        }
        if (e.NewItems != null) {
            Write($"starting new index: {e.NewStartingIndex}, ");
            Write($"new items: ");
            foreach (var item in e.NewItems) WriteLine($"{item} ");
        }
        WriteLine();
    }

    public static void Main() {
        var data=new ObservableCollection<string>();
        data.CollectionChanged += data_changed;
        data.Add("first");
        // -> Add: starting new index: 0, new items: first
        data.Add("second");
        // -> Add: starting new index: 1, new items: second 
        data.Insert(1, "third");
        // -> Add: starting new index: 1, new items: third
        data.Remove("first");
        // -> Remove: starting old index: 0, old items: first
    }
}
