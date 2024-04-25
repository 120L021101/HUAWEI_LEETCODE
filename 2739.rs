impl Solution {
    pub fn distance_traveled(main_tank: i32, additional_tank: i32) -> i32 {
        let mut oil_amount = main_tank;
        let mut saved_oil = additional_tank;
        let mut kilometers: i32 = 0;
        loop {
            let kilometer = oil_amount / 5;
            kilometers += kilometer * 50;

            oil_amount = oil_amount % 5;
            if (saved_oil < kilometer) {
                oil_amount += saved_oil;
                saved_oil = 0;
            } else {
                oil_amount += kilometer;
                saved_oil -= kilometer;
            }
            if (oil_amount < 5) {
                kilometers += oil_amount * 10;
                break;
            }
        }
        kilometers
    }
}