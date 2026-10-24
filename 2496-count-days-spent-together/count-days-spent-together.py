class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        arriveAliceDay = self.get_date_value(arriveAlice)
        leaveAliceDay = self.get_date_value(leaveAlice)

        arriveBobDay = self.get_date_value(arriveBob)
        leaveBobDay = self.get_date_value(leaveBob)

        if arriveAliceDay > arriveBobDay:
            return self.calculate(arriveBobDay, leaveBobDay, arriveAliceDay, leaveAliceDay)
        else:
            return self.calculate(arriveAliceDay, leaveAliceDay, arriveBobDay, leaveBobDay)
    
    def calculate(self, a1, l1, a2, l2):
        if a2 > l1:
            return 0
        if l1 < l2:
            return l1 - a2 + 1
        else:
            return l2 - a2 + 1

    def get_date_value(self, arriveAlice):
        month = int(arriveAlice.split("-")[0])
        date = int(arriveAlice.split("-")[1])

        day_months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

        output = 0
        for m in range(month-1):
            output += day_months[m]
        
        return output + date