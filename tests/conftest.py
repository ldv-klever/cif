import os
import pytest


def pytest_collection_modifyitems(config, items):
    cif_path = os.environ.get('CIF', 'cif')

    skip_arm = pytest.mark.skipif(
        'arm' not in os.path.basename(cif_path),
        reason='arm cif is not available'
    )

    skip_not_arm = pytest.mark.skipif(
        'arm' in os.path.basename(cif_path),
        reason='arm cif is available'
    )

    skip_aarch64 = pytest.mark.skipif(
        'aarch64' not in os.path.basename(cif_path),
        reason='aarch64 cif is not available'
    )

    skip_x86_64 = pytest.mark.skipif(
        'cif' != os.path.basename(cif_path),
        reason='x86_64 cif is not available'
    )

    for item in items:
        if 'arm' in item.keywords:
            item.add_marker(skip_arm)

        if 'not_arm' in item.keywords:
            item.add_marker(skip_not_arm)

        if 'aarch64' in item.keywords:
            item.add_marker(skip_aarch64)

        if 'x86_64' in item.keywords:
            item.add_marker(skip_x86_64)
