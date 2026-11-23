import csv
import io
import json
import logging

import requests

# Configure logging
logger = logging.getLogger()
logging.basicConfig(level=logging.INFO)

# API endpoint for daily consumption in FOCUS 1.1 format
API_URL = "https://api-enterprise-dashboard.otc-service.com/v2/daily/consumption/focus/"
TOKEN = "<YOUR_TOKEN_HERE>"  # Service account or API token

headers = {
    "Accept": "text/csv",
    "Authorization": f"Bearer {TOKEN}",
}

# Make GET request with query parameters
try:
    response = requests.get(
        API_URL,
        headers=headers,
        params={
            "date": "2025-02-02",
            "contract": 1000012345,
            "show_tag": True,
            "format": "csv",
        },
        timeout=60,
    )
    response.raise_for_status()

    # The first row contains column names. Nested values (such as Tags) are
    # JSON strings and null values are empty cells.
    reader = csv.DictReader(io.StringIO(response.text))
    for row in reader:
        tags = json.loads(row["Tags"]) if row.get("Tags") else None
        logger.info(
            "Received charge: %s %s %s %s tags=%s",
            row["BillingPeriodStart"],
            row["ChargeDescription"],
            row["BilledCost"],
            row["BillingCurrency"],
            tags,
        )

except requests.exceptions.RequestException as e:
    logger.exception("Request failed: %s", str(e))
