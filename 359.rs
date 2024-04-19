use std::{collections::HashMap};
struct Logger {
    record : HashMap<String, i32>,
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Logger {

    fn new() -> Self {
        Logger {
            record: HashMap::new(),
        }
    }
    
    fn should_print_message(&mut self, timestamp: i32, message: String) -> bool {
        let temp = self.record.get(&message).cloned();
        if temp.is_none() {
            self.record.insert(message, timestamp);
            return true
        }
        if (timestamp - temp.unwrap()) < 10 {
            return false
        }
        self.record.insert(message, timestamp);
        true
    }
}