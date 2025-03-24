// ko

using System;
using System.Collections.Generic;

public class IdStore100 : IEnumerable<int> {
    private int[] ids;
    private int next_idx=0;

    public IdStore100() {
        ids = new int[100];
    }

    public void add(int id) {
        ids[next_idx++] = id;
    }

    // necessary due to inheritance from IEnumerable<int>
    public IEnumerator<int> GetEnumerator() {
        return new IdEnumerator(this, next_idx - 1);
    }

    // necessary due to inheritance from IEnumerable
    System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator() {
        return GetEnumerator();
    }

    public class IdEnumerator : IEnumerator<int> {
        private int curr_idx = -1;
        private int last_idx;
        private IdStore100 store;

        public IdEnumerator(IdStore100 store, int last_idx) {
            this.store = store;
            this.last_idx = last_idx;
        }

        public bool MoveNext() {
            if (curr_idx + 1 <= last_idx) {
                curr_idx++;
                return true;
            } else return false;
        }

        public int Current {
            get {
                try {
                    return store.ids[curr_idx];
                } catch (IndexOutOfRangeException) {
                    throw new InvalidOperationException();
                }
            }
        }

        // necessary due to inheritance from IEnumerable
        object System.Collections.IEnumerator.Current {
            get {
                return this.Current;
            }
        }

        public void Reset() {
            curr_idx = -1;
        }

        public void Dispose() {}
    }

    public static void Main() {
        IdStore100 store=new IdStore100();
        store.add(1);
        store.add(3);
        store.add(5);
        store.add(4);
        store.add(2);
        store.add(0);
        foreach (var id in store)
            Console.WriteLine(id);
    }
}
