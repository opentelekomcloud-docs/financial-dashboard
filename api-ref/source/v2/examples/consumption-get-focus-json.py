import logging

import requests

# Configure logging
logger = logging.getLogger()
logging.basicConfig(level=logging.INFO)

# API endpoint for daily consumption in FOCUS 1.1 format
API_URL = "https://api-enterprise-dashboard.otc-service.com/v2/daily/consumption/focus/"
TOKEN = "<YOUR_TOKEN_HERE>"  # Service account or API token

# format=json returns one JSON array, so response.json() buffers the full body
headers = {
    "Accept": "application/json",
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
            "format": "json",
        },
        timeout=60,
    )
    response.raise_for_status()

    charges = response.json()
    logger.info("Received %s charges", len(charges))
    for data in charges:
        logger.info(
            "Received charge: %s %s %s %s",
            data["BillingPeriodStart"],
            data["ChargeDescription"],
            data["BilledCost"],
            data["BillingCurrency"],
        )

except requests.exceptions.RequestException as e:
    logger.exception("Request failed: %s", str(e))
