class UserHashTable:
    def __init__(self, size=10):
        """Initialize the hash table with a given size."""
        self.size = size
        self.table = [[] for _ in range(size)]

    def _hash_function(self, username):
        """Hash function to map a username to an index."""
        return hash(username) % self.size

    def add_user(self, username, profile_data):
        """Add a user with the given username and profile data."""
        index = self._hash_function(username)
        # Check if the username already exists in the chain and update it if so
        for i, (existing_username, _) in enumerate(self.table[index]):
            if existing_username == username:
                self.table[index][i] = (username, profile_data)
                print(f"Updated user {username} at index {index}")
                return
        # Append new user if not found
        self.table[index].append((username, profile_data))
        print(f"Added user {username} at index {index}")

    def get_user(self, username):
        """Retrieve a user's profile data by username."""
        index = self._hash_function(username)
        for existing_username, profile_data in self.table[index]:
            if existing_username == username:
                return profile_data
        print(f"User {username} not found.")
        return None

# Example usage
user_table = UserHashTable()
user_table.add_user("alice123", {"name": "Alice", "age": 25, "location": "NY"})
user_table.add_user("bob456", {"name": "Bob", "age": 30, "location": "LA"})
print(user_table.get_user("alice123"))  # Should print Alice's profile
print(user_table.get_user("charlie789"))  # Should print "User charlie789 not found."
