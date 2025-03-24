// @copyright 2018 Günter Kolousek

using System;

namespace logsimy {
  namespace variables {
    public enum NotificationReason {
        changed,
        reset
    }

    public sealed class Variable {
        public Variable(string name="") {
            this.name = name;
        }

        public string name { get; set; }
        private bool _value;

        public bool value {
            get {
                return _value;
            }
            set {
                if (_value != value) {
                    _value = value;
                    if (notify != null)
                        notify(this, NotificationReason.changed);
                }
            }
        }

        public void reset(bool v=false) {
            _value = v;
            if (notify != null)
                notify(this, NotificationReason.reset);
        }

        public delegate void NotifyHandler(Variable v, NotificationReason reason);
        public event NotifyHandler notify;
    }

    public interface Observer {
        void update(Variable v, NotificationReason r);
    }

    public static class Utilities {
        public static void connect(Variable src, Variable dst) {
            src.notify += ((v, reason) => dst.value = v.value);
        }

        public static void enable_logging(Variable src, string prefix="") {
            src.notify += ((v, reason) => Console.WriteLine(prefix +
                v.name + ": " +
                v.value.ToString() + " (" + reason.ToString() + ")"));
        }

        public static void inform(Variable src, Observer obs) {
            src.notify += ((v, reason) => obs.update(v, reason));
        }
    }
  }
}
