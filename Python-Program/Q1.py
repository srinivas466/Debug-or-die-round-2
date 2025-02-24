class BankAccount:
    def _init_(self, owner, balance=0):
        self.owner = owner
        self.balance = balance

    def deposit(self, amount):
        if amount <= 0:
            print("Deposit amount must be positive.")
        else:
            self.balance += amount
            print(f"Deposited: ${amount}")

    def withdraw(self, amount):
        if amount > self.balance:
            print("Insufficient funds.")
        elif amount <= 0:
            print("Withdrawal amount must be positive.")
        else:
            self.balance -= amount
            print(f"Withdrew: ${amount}")

    def get_balance():
        return self.balance

# Program starts here
account = BankAccount("Alice", 100)
print("Welcome,", account.owner)

while True:
    action = input("Choose action (deposit, withdraw, balance, exit): ").lower()
    if action == "deposit":
        amt = float(input("Enter amount to deposit: "))
        account.deposit(amt)
    elif action == "withdraw":
        amt = float(input("Enter amount to withdraw: "))
        account.withdraw(amt)
    elif action == "balance":
        print("Current balance: $", account.get_balance)
    elif action == "exit":
        print("Thank you for banking with us.")
        break
    else
        print("Invalid action. Try again.")